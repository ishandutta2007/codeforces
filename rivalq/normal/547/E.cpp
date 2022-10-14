#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC
using namespace std;


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}

template<typename T>
struct suffix_array{
	T s;
	vector<int>p,c;
	vector<int>lcp,len;
	int n;
	suffix_array(T str){
		s=str;
		n=s.size();p.resize(n);
		c.resize(n);lcp.resize(n);
		len.resize(n);
	}
	void count_sort(vector<int>&p,vector<int>&c){
		int n=p.size();
		vector<int>cnt(n);
		for(auto x:c)cnt[x]++;
		vector<int>p_new(n),pos(n);pos[0]=0;
		for(int i=1;i<n;i++)pos[i]=pos[i-1]+cnt[i-1];
		for(auto x:p){
			int i=c[x];
			p_new[pos[i]]=x;pos[i]++;
		}
		p=p_new;
	}
	void build(){
		vector<pair<int,int>>a(n);
		for(int i=0;i<n;i++)a[i]={s[i],i};
		sort(all(a));
		for(int i=0;i<n;i++)p[i]=a[i].y;
		c[p[0]]=0;
		for(int i=1;i<n;i++)c[p[i]]=(a[i].x==a[i-1].x)?c[p[i-1]]:c[p[i-1]]+1;	
		int k=0;
		while((1<<k)<n){
			for(int i=0;i<n;i++)p[i]=(p[i]-(1<<k)+n)%n;
			count_sort(p,c);
			vector<int>c_new(n);
			c_new[p[0]]=0;
			for(int i=1;i<n;i++){
				pii prev={c[p[i-1]],c[(p[i-1]+(1<<k))%n]};
				pii now={c[p[i]],c[(p[i]+(1<<k))%n]};
				if(now==prev){
					c_new[p[i]]=c_new[p[i-1]];
				}
				else{
					c_new[p[i]]=c_new[p[i-1]]+1;
				}
			}
			c=c_new;
			k++;
		}
		for(int i=0;i<n;i++){
			len[i]=n-p[i];
		}
		k=0;
		for(int i=0;i<n-1;i++){
			int pi=c[i];int j=p[pi-1];
			while(s[i+k]==s[j+k])k++;
			lcp[pi]=k;k=max(0,k-1);
		}

	}

};




vector<int>label,s;
vector<string>a;

template<typename T>
struct Fenwick{
    vector<T> tree;
    Fenwick(int n){
        tree.resize(n);
    }

    T query(int i){
        int sum=0;
        while(i){
           sum+=tree[i];
           i-=i&(-i);
       }  
       return sum;
    }
    void update(int i,int n,T val){
       while(i<=n){
          tree[i]+=val;
          i+=i&(-i);
       }
    }
};



int solve(){
	int n,q;cin>>n>>q; 
	a.resize(n+1);
	set<int>imp;
	map<int,int>mp;
	rep(i,1,n+1){
		cin>>a[i];
		imp.insert(sz(label));
		mp[sz(label)]=a[i].length();
		for(auto j:a[i])s.pb(j),label.pb(i);
		label.pb(0);
		s.pb(-i);
	}
	suffix_array<vector<int>> sa(s);
	sa.build();
	int m=s.size();
	vector<int>pl(m),impl;
	for(int i=0;i<m;i++)pl[i]=label[sa.p[i]];
	for(int i=0;i<m;i++){
		if(imp.count(sa.p[i])){
			impl.pb(i);
		}
	}
	//  impl contains locations of original strings in p array and lcp array
	// we need to find two pointers for each elements in impl
	// such mp[element]=min_lcp to that pointer;
	vector<pii>vec(n+1);
	for(auto i:impl){
		int l=i,r=m-1;
		int len=mp[sa.p[i]];
		vec[pl[i]].x=i,vec[pl[i]].y=i;
		while(l<=r){
			int mid=(l+r)/2;
			bool f=1;
			for(int k=0;k<len;k++){
				int x1=s[sa.p[i]+k];
				int x2=s[sa.p[mid]+k];
				if(x1!=x2){
					f=0;
					break;
				}
			}
			if(f){
				l=mid+1;
				vec[pl[i]].y=mid;
			}
			else{
				r=mid-1;
			}
		}
		l=1,r=i;
		while(l<=r){
			int mid=(l+r)/2;
			bool f=1;
			for(int k=0;k<len;k++){
				int x1=s[sa.p[i]+k];
				int x2=s[sa.p[mid]+k];
				if(x1!=x2){
					f=0;
					break;
				}
			}
			if(f){
				r=mid-1;
				vec[pl[i]].x=mid;
			}
			else{
				l=mid+1;
			}
		}
		//cout<<pl[i]<<" "<<len<<" "<<vec[pl[i]]<<endl;
	}
	// now we need to count number of intgers in range [L,R] with values belongs to (l,r)
	// pl is our range query array.
	// we will answer every query offline.
	vector<int>ans(q+1);
	vector<pair<int,pii>>query;
	rep(i,1,q+1){
		int l,r,k;cin>>l>>r>>k;
		query.pb({l,{i,k}});
		query.pb({r+1,{-i,k}});
	}
	sort(query.begin(),query.end());
	Fenwick<int>fn(m+1);
	map<int,vector<int>>st;
	for(int i=1;i<m;i++){
		if(pl[i]>0){
			fn.update(i,m,1);
			st[pl[i]].pb(i);
		}	
	}
	int j=0;
	rep(i,1,n+1){
		while(j<sz(query) && query[j].x==i){
			int idx=query[j].y.x;
			int l=vec[query[j].y.y].x;
			int r=vec[query[j].y.y].y;
			int val=fn.query(r)-fn.query(l-1);
			if(idx>0)ans[idx]+=val;
			else ans[-idx]-=val;
			j++;
		}
		for(auto j:st[i]){
			fn.update(j,m,-1);
		}

	}
	rep(i,1,q+1){
		cout<<ans[i]<<endl;
	}
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef SIEVE
    sieve();
    #endif
    #ifdef NCR
    init();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
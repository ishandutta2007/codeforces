#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
#define int            long long
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

struct suffix_array{
	string s;
	vector<int>p,c;
	vector<int>lcp,len;
	int n;
	suffix_array(string str){
		s=str;
		n=s.size();p.resize(n);
		c.resize(n);lcp.resize(n);
		len.resize(n+1);
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
		vector<pair<char,int>>a(n);
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
			lcp[pi]=k;k=max(0LL,k-1);
		}

	}

};



int solve(){
 	string s1,s2;
 	cin>>s1>>s2;
 	string t=s1+'?'+s2+'#';
 	int n=s1.length();
 	suffix_array sa(t);
 	sa.build();
 	int mi=hell;int j=-1;
 	int m=t.length();
 	for(int i=2;i<m;i++){
 		if(sa.lcp[i]==0)continue;
 		if(sa.p[i]>=n && sa.p[i-1]>=n)continue;
 		if(sa.p[i]<n && sa.p[i-1]<n)continue;
 		if(sa.lcp[i-1]>=sa.lcp[i] || (i+1<m && sa.lcp[i]<=sa.lcp[i+1]))continue;
 		int val=sa.lcp[i-1];
 		if(i+1<m)maxs(val,sa.lcp[i+1]);
 		//cout<<i<<endl;
 		val++;
 		if(mi>val){
 			j=i;mi=val;
 		}
 	}
 	//for(int i=2;i<m;i++){
 	//	cout<<t.substr(sa.p[i],m-sa.p[i])<<"   "<<t.substr(sa.p[i-1],m-sa.p[i-1])<<" "<<sa.lcp[i]<<endl;
 	//}
 	if(j==-1)cout<<-1<<endl;
 	else cout<<mi<<endl;
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
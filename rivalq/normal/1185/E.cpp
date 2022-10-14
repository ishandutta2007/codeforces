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


int solve(){
 int n,m;cin>>n>>m;
 vector<pii>vec(26,{-1,-1});
 vector<vector<char>>a(n+1,vector<char>(m+1));
 pii p={-1,-1};
 bool f=1;
 rep(i,1,n+1){
 	rep(j,1,m+1){
 		cin>>a[i][j];
 		if(a[i][j]=='.')continue;
 		if(vec[a[i][j]-97]==p)vec[a[i][j]-97]={i,j};
 		else{
            if(i!=vec[a[i][j]-97].x && j!=vec[a[i][j]-97].y)f=0;
 		}
 	}
 }
 if(f==0){
 	cout<<"NO"<<endl;return 0;
 }
 int cnt=-1;
 vector<vector<int>>v(26);
 for(int i=0;i<26;i++){
 	if(vec[i]==p)continue;
    int cnt1=0,cnt2=0;
    for(int j=1;j<=m;j++){
    	if(a[vec[i].x][j]==i+97)cnt1++;
    }
    for(int k=1;k<=n;k++){
    	if(a[k][vec[i].y]==i+97)cnt2++;
    }
    if(cnt1>1 && cnt2>1){
    	cout<<"NO"<<endl;return 0;
    }
    if(cnt1==1 && cnt2==1){
      v[i]={vec[i].x,vec[i].y,vec[i].x,vec[i].y};
      cnt=i;
      continue;	
    }
    if(cnt1>1){
    	pii ext1=vec[i];
    	pii ext2=vec[i];
        for(int j=1;j<=m;j++){
        	if(a[vec[i].x][j]==i+97){
        		ext1={vec[i].x,j};
        		break;
        	}
        }
        for(int j=m;j>0;j--){
        	if(a[vec[i].x][j]==i+97){
        		ext2={vec[i].x,j};
        		break;
        	}
        }
        for(int j=ext1.y;j<=ext2.y;j++){
        	if(a[vec[i].x][j]=='.'){
        		cout<<"NO"<<endl;
        		return 0;
        	}
        	if(a[vec[i].x][j]<i+97){
        		cout<<"NO"<<endl;return 0;
        	}
        }
        vector<int>temp={ext1.x,ext1.y,ext2.x,ext2.y};
        v[i]=temp;
        cnt=i;
    }
    if(cnt2>1){
    	pii ext1=vec[i];
    	pii ext2=vec[i];
        for(int j=1;j<=n;j++){
        	if(a[j][vec[i].y]==i+97){
        		ext1={j,vec[i].y};
        		break;
        	}
        }
        for(int j=n;j>0;j--){
        	if(a[j][vec[i].y]==i+97){
        		ext2={j,vec[i].y};
        		break;
        	}
        }
        for(int j=ext1.x;j<=ext2.x;j++){
        	if(a[j][vec[i].y]=='.'){
        		cout<<"NO"<<endl;
        		return 0;
        	}
        	if(a[j][vec[i].y]<i+97){
        		cout<<"NO"<<endl;return 0;
        	}
        }
        vector<int>temp={ext1.x,ext1.y,ext2.x,ext2.y};
        v[i]=temp;
        cnt=i;
    }
 }
 cout<<"YES"<<endl;
 for(int i=0;i<cnt;i++){
 	if(v[i].empty())v[i]=v[cnt];
 }
 cout<<cnt+1<<endl;
 for(int i=0;i<=cnt;i++){
 	for(auto j:v[i])cout<<j<<" ";cout<<endl;
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
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
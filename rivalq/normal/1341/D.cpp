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
//0-1110111
//1-0010010
//2-1011101
//3-1011011
//4-0111010
//5-1101011
//6-1101111
//7-1010010
//8-1111111
//9-1111011
string num[10]={"1110111","0010010","1011101","1011011","0111010","1101011","1101111","1010010","1111111","1111011"};
int getmin(string &s,int n){
   string ch=num[n];
   int cnt=0;
   for(int i=0;i<7;i++){
   	 if(ch[i]=='0' && s[i]=='1')return -1;
   	 if(ch[i]=='1' && s[i]=='0')cnt++;
   } 
   return cnt;
}
int get(string &s){
	int mi=hell;
	for(int i=0;i<=9;i++){
		int g=getmin(s,i);
		if(g!=-1)mins(mi,g);
	}
	return mi;
}
int give(string &s){
	int mi=hell;
	int j;
	for(int i=0;i<=9;i++){
		int g=getmin(s,i);
		if(g!=-1){
			if(mi>=g)mi=g,j=i;
		}
	}
	return j;
}
int off(string &s){
	int cnt=0;
	for(int i=0;i<7;i++)cnt+=(s[i]=='0');
    return cnt;		
} 
void print(vector<int> &v){
  for(auto i:v)cout<<i<<" ";cout<<endl;
    exit(0);
}
int dp[2002][2002];
vector<string> v;
int zeno(int i,int k,int n){
    if(k<0)return 0;
    if(i==n && k==0)return 1;
    if(i==n && k!=0) return 0;
    if(dp[i][k]!=-1)return dp[i][k];
    for(int j=9;j>=0;j--){
       if(getmin(v[i],j)!=-1){
          int moves=getmin(v[i],j);
          if(zeno(i+1,k-moves,n)>0)return dp[i][k]=j+1;
       }
    }
    return dp[i][k]=0;
}
int solve(){
 mem1(dp); 
 int n,k;cin>>n>>k;
 int s1=0,s2=0;
 v.resize(n);
 rep3(n)cin>>v[i];
 vector<int> ans(n);
 if(zeno(0,k,n)==0){
   cout<<-1<<endl;return 0;
 }
 for(int i=0;i<n;i++){
    int number=zeno(i,k,n);
    number--;
    cout<<number;
    k=k-getmin(v[i],number);
 }
 cout<<endl;
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
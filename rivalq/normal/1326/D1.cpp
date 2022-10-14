//https://c...content-available-to-author-only...s.com/problemset/problem/1326/D1
#include<bits/stdc++.h>
#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define inarr(arr,n)   rep(i,a,n)cin>>arr[i]
#define ll             long long int
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define IOS            ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pi             3.1415926536
#define hell           1000000007
#define narak          998244353
const int inf1=1e9;
const ll inf2=1e18;
const int N=100000;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
#include <unistd.h> // not included in bits/stdc++.h
unsigned ll mix(unsigned ll a, unsigned ll b, unsigned ll c){
    a=a-b;  a=a-c;  a=a^(c >> 13);
    b=b-c;  b=b-a;  b=b^(a << 8);
    c=c-a;  c=c-b;  c=c^(b >> 13);
    a=a-b;  a=a-c;  a=a^(c >> 12);
    b=b-c;  b=b-a;  b=b^(a << 16);
    c=c-a;  c=c-b;  c=c^(b >> 5);
    a=a-b;  a=a-c;  a=a^(c >> 3);
    b=b-c;  b=b-a;  b=b^(a << 10);
    c=c-a;  c=c-b;  c=c^(b >> 15);
    return c;
}
struct polyhash{
   ll *hash1;
   ll *hash2;
   ll base1,base2; 
   ll  hell1,hell2;
   polyhash(int n){
       hash1=new ll[n+10];
       hash2=new ll[n+10];
       unsigned ll seed = mix(clock(), time(NULL), getpid());
       srand(seed);
       base1=rand()%2000+29;
       base2=rand()%2000+31;
       hell1=rand()*rand()%800000000+200000007;
       hell2=rand()*rand()%800000000+200000009;
       hash1[0]=hash2[0]=1;
       rep(i,1,n+10) hash1[i]=hash1[i-1]*base1%hell1;
       rep(i,1,n+10) hash2[i]=hash2[i-1]*base2%hell2;
   }
   string LPP(string t){
       int n=t.length();
       ll hp1=0,hp2=0,hs1=0,hs2=0;
       ll l=0;
       for(int i=0;i<n;i++){
           hp1=(hp1+t[i]*hash1[i])%hell1;
           hs1=(hs1*base1+t[i])%hell1;
           hp2=(hp2+t[i]*hash2[i])%hell2;
           hs2=(hs2*base2+t[i])%hell2;
           if(hp1==hs1 && hs2==hp2)l=i+1;
       }
       return t.substr(0,l);
   }
}poly1(1000000);
bool ispalindrome(string s){
    string t=s;
    reverse(all(s));
    return t==s;
}
int solve(){
  string s;cin>>s;
  int n=s.length();
  int l=0;int r=n-1;
  if(ispalindrome(s)){
      cout<<s<<endl;return 0;
  }
  while(s[l]==s[r])l++,r--;          
  string ans1=s.substr(0,l);
  string ans2=ans1;reverse(all(ans2));
  string t1=s.substr(l,n-2*l);
  string t2=t1;reverse(all(t2)); 
  string ans3=poly1.LPP(t1);
  string ans4=poly1.LPP(t2);
  if(ans3.size()>=ans4.size()){
      cout<<ans1+ans3+ans2<<endl;
  }         
  else{
      cout<<ans1+ans4+ans2<<endl;
  }
 return 0;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef cat
    cat();
    #endif
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
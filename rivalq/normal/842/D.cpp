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
struct node{
   node* sons[2];
   int cnt=0;
};
node* create(){
       node* temp=new node();
       temp->sons[0]=NULL;
       temp->sons[1]=NULL;
       temp->cnt=0;
       return temp;
} 
template<typename node>
struct trie{
   node* root=new node();
   void insert(int p){
       node* temp=root;
       for(int j=20;j>=0;j--){
           temp->cnt++;
           int k=(((1LL<<j)&p)!=0);
           if(temp->sons[k]==NULL){
               temp->sons[k]=create();
               temp=temp->sons[k];
           }
           else{
               temp=temp->sons[k];
           } 
       }
       temp->cnt++;
   }
   void erase(int p){
       node* temp=root;
       for(int j=20;j>=0;j--){
           temp->cnt--;
           if(p&(1<<j))temp=temp->sons[1];
           else temp=temp->sons[0];
       }
       temp->cnt--;
   }
   int query(int val){
      node* temp=root;
      int ans=0;
      for(int j=20;j>=0;j--){
      	 if((1<<j)&val){
            if(temp->sons[1])temp=temp->sons[1];
            else temp=temp->sons[0],ans+=(1<<j);
      	 }
      	 else{
      	 	if(temp->sons[0])temp=temp->sons[0];
            else temp=temp->sons[1],ans+=(1<<j);
      	 }
      } 
      return ans;
   }
};
trie<node>tr;
int solve(){
 int n,m;cin>>n>>m;
 set<int>s;
 rep3(n){
 	int t;cin>>t;
 	s.insert(t);
 }
 for(int i=0;i<(1<<20);i++){
 	 if(s.count(i)==0)tr.insert(i);
 }
 int last=0;
 rep3(m){
 	int x;cin>>x;
 	last^=x;
 	cout<<tr.query(last)<<endl;
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
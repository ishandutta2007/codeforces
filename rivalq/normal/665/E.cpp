#include<stdio.h>
#include<map>
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
       for(int j=30;j>=0;j--){
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
       for(int j=30;j>=0;j--){
           temp->cnt--;
           if(p&(1<<j))temp=temp->sons[1];
           else temp=temp->sons[0];
       }
       temp->cnt--;
   }
   ll query(int k,int val){
      node* temp=root;
      ll cnt=0;
      for(int j=30;j>=0 && temp;j--){
      	 if((1<<j)&k){
      	 	if(val&(1<<j)){
      	 		if(temp->sons[0])temp=temp->sons[0];
      	 		else break;
      	 	}
      	 	else{
      	 		if(temp->sons[1])temp=temp->sons[1];
      	 		else break;
      	 	}
      	 }
      	 else{
      	 	if(val&(1<<j)){
      	 		if(temp->sons[0])cnt+=temp->sons[0]->cnt;
      	 		temp=temp->sons[1];
      	 	}
      	 	else{
      	 		if(temp->sons[1])cnt+=temp->sons[1]->cnt;
      	 		temp=temp->sons[0];
      	 	}
      	 }
      }
      return cnt;
   }
};
trie<node> tr;
int a[1000001],p[1000001];
int solve(){
 int n,k;
 scanf("%d %d",&n,&k);
 ll ans=0;
 tr.insert(0);
 map<int,int>mp;
 mp[0]++;
 rep(i,1,n+1){
 	scanf("%d",&a[i]);
 	p[i]=p[i-1]^a[i];
 	mp[p[i]]++;
 	tr.insert(p[i]);
    if(mp.count(p[i]^k))ans+=mp[p[i]^k];
 	ans+=tr.query(k,p[i]);
 }
 printf("%llu",ans);
 return 0;
}
signed main(){
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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
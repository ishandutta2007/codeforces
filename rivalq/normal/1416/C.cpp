

#include<iostream>
#include<vector>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
#define int            long long		
#define pb             push_back
#define endl           "\n"
#define x              first
#define y              second
#define pii            pair<int,int>
using namespace std;


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}

int n;
int inv1[100],inv2[100];
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
struct Trie{
   node* root=new node();
   void insert(int p){
       node* temp=root;
       for(int j=30;j>=0;j--){
           temp->cnt++;
           int k=(((1LL<<j)&p)!=0);
           if(k && temp->sons[0]){
           		inv1[j]+=temp->sons[0]->cnt;
           }
           if(!k && temp->sons[1]){
           		inv2[j]+=temp->sons[1]->cnt;
           }
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
   int query(){
      // function of query
   }
};
Trie<node>tr;
int solve(){
 	cin>>n;
 	vector<int>b(n+1);
 	rep(i,1,n+1){
 		int t;cin>>t;
 		tr.insert(t);
 	}
 	int ans=0;
 	int x=0;
 	for(int j=29;j>=0;j--){
 		int k=(1<<j);
 		ans+=min(inv1[j],inv2[j]);
 		if(inv1[j]<inv2[j])x+=k;
 	}
 	cout<<ans<<" "<<x<<endl;
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
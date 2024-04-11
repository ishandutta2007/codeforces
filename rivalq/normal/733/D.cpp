//https://codeforces.com/contest/733/problem/D
#include<bits/stdc++.h>
#define lop(i,n,a) for(int i=0;i<n;i+=a)
#define rep(i,n,a) for(int i=a;i<n;i++)
#define ll long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define endl "\n"
#define eb emplace_back
#define fr first
#define sc second
#define pii pair<int,int>
#define mp make_pair
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret return 0
#define pi 3.1415926536
#define mod 1000000007
using namespace std;
pii func(int a,int b){ 
    if(a>b)
 	return mp(a,b);
 	return mp(b,a);
} 
int solve(){
  int n;cin>>n;
  map<pii,vector<pii>> mp;
  lop(i,n,1){
    int a,b,c;
    cin>>a>>b>>c;
    mp[func(a,b)].pb({c,i});
    if(func(b,c)!=func(a,b))  
    mp[func(b,c)].pb({a,i});
    if(func(a,b)!=func(a,c) && func(a,c)!=func(b,c))
    mp[func(a,c)].pb({b,i});
  }
 int ma=0;int arr[2]={0},k=0;
 map<pii,vector<pii>>::iterator itr;
  for(itr=mp.begin();itr!=mp.end();itr++){
     int a=itr->fr.fr;
     int b=itr->fr.sc;
     int c;
     sort(all(itr->sc));
     reverse(all(itr->sc));
     //sort(all(v),greater<pii>());
     if(itr->sc.size()==1)c=itr->sc[0].fr;
     else c=itr->sc[0].fr+itr->sc[1].fr;
     if(ma<min(a,min(b,c))){
         ma=min(a,min(b,c));
         k=(itr->sc.size()==1)?1:2;
         if(k==1)arr[0]=itr->sc[0].sc+1,arr[1]=0;
         else arr[0]=itr->sc[0].sc+1,arr[1]=itr->sc[1].sc+1;
     }  
  }
  cout<<k<<endl;
  cout<<arr[0]<<endl;
  if(k!=1)cout<<arr[1]<<endl;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ll t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}
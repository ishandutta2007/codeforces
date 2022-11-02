#include<bits/stdc++.h>
using namespace std;
int main(){
//  freopen("in.in","r",stdin);
//  freopen("out.out","w",stdout);
  int n;
  cin>>n;
  if(n<4) {
    return puts("0"),0;
  }
  typedef long long LL;
  vector<int> prime;
  vector<int> flag;
  flag.resize(n+1);
  prime.resize(n);
  int pn=0;
  for(int i=2; i<=(n>>1); i++){
    if(!flag[i]){
      prime[pn++]=i;
      if((LL)i*i<=n){
        for(int j=i*i; j<=n; j+=i) flag[j]=1;
      }
    }
  }
  
//  for(int i=0; i<pn; i++) cout<<prime[i]<<' ';cout<<endl;
  
  vector<int> tmp;
  vector<pair<int,int>> ans;
  ans.resize(n);
  tmp.resize(n);
  int ansn=0;
  int tmpn=0;
  
  for(int i=pn-1,j; i; i--){
    j=n/prime[i];
    tmpn=0;
    for(int k=1; k<=j; k++){
      if(flag[prime[i]*k]!=2){
        tmp[tmpn++]=k;
      }
    }
    if(tmpn&1){
      for(int k=4; k<tmpn; k+=2){
        ans[ansn++]={prime[i]*tmp[k-1],prime[i]*tmp[k]};
        flag[prime[i]*tmp[k-1]]=2;
        flag[prime[i]*tmp[k]]=2;
      }
      ans[ansn++]={prime[i]*tmp[0],prime[i]*tmp[2]};
      flag[prime[i]*tmp[0]]=2;
      flag[prime[i]*tmp[2]]=2;
    }else{
      for(int k=1; k<tmpn; k+=2){
        ans[ansn++]={prime[i]*tmp[k-1],prime[i]*tmp[k]};
        flag[prime[i]*tmp[k-1]]=2;
        flag[prime[i]*tmp[k]]=2;
      }
    }
  }
  
  tmpn=0;
  for(int i=2; i<=n; i+=2){
    if(flag[i]!=2){
      tmp[tmpn++]=i;
    }
  }
  
  for(int i=1; i<tmpn; i+=2){
    ans[ansn++]={tmp[i-1],tmp[i]};
  }
  
  printf("%d\n",ansn);
  for(int i=0; i<ansn; i++) printf("%d %d\n",ans[i].first,ans[i].second);
  
  return 0;
}
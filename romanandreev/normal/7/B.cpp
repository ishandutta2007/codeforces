#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <map>
#include <set>
using namespace std;
#define ll int64_t

int a[1000];
int main() {
  //freopen("b.in","r",stdin);
  //freopen("b.out","w",stdout);
  int t,m,n;
  scanf("%d%d\n",&t,&m);
  int block=0;
  for (int i=1;i<=m;i++)
    a[i]=0;
  char cc;
  for (int ii=0;ii<t;ii++){
    scanf("%c",&cc);
    //cerr<<cc<<endl;
    if (cc=='a'){
        //cerr<<"all"<<endl;
      for (int i=2;i<=5;i++)
        scanf("%c",&cc);
      scanf("%d\n",&n);
      //cerr<<n;
      bool bl1=true;
      for (int i=1;i<=m-n+1;i++){
        bool bl=true;
        for (int j=i;j<i+n;j++){
          if (a[j]!=0)
            bl=false;
        }
        if (bl){
          block++;
          cout<<block<<endl;
          for (int j=i;j<i+n;j++){
            a[j]=block;
          }
          bl1=false;
          break;
        }
      }
      if (bl1)
        cout<<"NULL"<<endl;
    } else
    if (cc=='e'){
        //cerr<<"err"<<endl;
      for (int i=2;i<=5;i++)
        scanf("%c",&cc);
      scanf("%d\n",&n);
      bool bl=true;
	  if (n!=0)
      for (int i=1;i<=m;i++)
        if (a[i]==n){
            a[i]=0;
            bl=false;
        }
      if (bl)
       cout<<"ILLEGAL_ERASE_ARGUMENT"<<endl;
    } else{
      int tkx=0;
      for (int i=1;i<=m;i++) if (a[i]!=0){
        tkx++;
        a[tkx]=a[i];
      }
      for (int i=tkx+1;i<=m;i++)
        a[i]=0;
      string s;
      getline(cin,s);
    }
  }
  return 0;
}
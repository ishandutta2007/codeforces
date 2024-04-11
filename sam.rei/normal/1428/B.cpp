#include "bits/stdc++.h"

using namespace std;
//static int w[100000];
//static char s[300001];
static bool reach[300001];
int main(){
  //   ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
   int n;
   cin >>n;
   //cout<<n<<endl;
   int k;
   while(n-->0){
     cin>>k;
     //cout<<k<<endl;
     std::string s;
     //getline(cin,s);
     //getline(cin,s);
     cin>>s;
     //cout<<s<<endl;
     for( int i=0;i<k;++i)reach[i] = false;
     reach[k] = false;
     bool allleft = true;
     bool allright = true;
     for(int i=0;i<k;++i){
       switch(s[i]){
       case '<':
	 allleft = false;break;
       case '-':
	 reach[i] = reach[i+1] = true;break;
       case '>':
	 allright =false;break;
       }
     }
     reach[0]|= reach[k];
     int r=0;
     if(allleft||allright){r=k;}
     else{
       for(int i=0;i<k;++i)if(reach[i])++r;
     }
     cout<<r<<endl;
   }
   //   cout<<flush;
   return 0;
}
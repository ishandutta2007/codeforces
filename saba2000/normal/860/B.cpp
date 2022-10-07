#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
int r[1009];
char S[80009][20];
string s[80009];
unordered_map<string,int> M;

set<string> T[100009];
main()
{
    int n;
    cin>>n;
   for (int i=0; i<n; i++)
   {
       scanf("%s",S[i]);
       s[i]=S[i];
       for (int p=0; p<s[i].size(); p++)
       {

           string k="";
           for (int j=p; j<s[i].size(); j++)
            {k+=s[i][j];
           // cout<<k<<endl;
            if(T[i].find(k)==T[i].end()) {M[k]++;T[i].insert(k);}
            }

       }
   }
   for (int i=0; i<n; i++)
   {

       int ans=10;
       string ans1="";
       for (int p=0; p<s[i].size(); p++)
       {
           string k="";
           for (int j=p; j<s[i].size(); j++){
            k+=s[i][j];
            if(M[k]==1 && j-p+1<ans){ans=j-p+1; ans1=k;}}

       }
     // cout<<ans1<<endl;
      for(int j=0;j<ans1.size(); j++)
        printf("%c",ans1[j]);
        printf("\n");
   }

}
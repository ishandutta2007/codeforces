#include<bits/stdc++.h>
#define L int
#define r return
#define e(i,a,b) for(L i=a;i<=b;i++)
using namespace std;
L n,m,s[2333],t[2333];unordered_map<string,L> D[2333][11];
L S(L C,L F,string I){if(D[C][F][I])r D[C][F][I];if(C==n+1&&I=="0000")r 0;string _=I;L P=C,R=1<<30,z=0;e(f,1,9){C=P;I=_;z=0;e(i,0,3)if(I[i]-'0'==f)z++,I[i]='0';e(i,0,3)if(I[i]=='0'&&s[C]==f)I[i]=t[C]+'0',C++,z++;sort(I.begin(),I.end());if(C!=P||I!=_)R=min(R,S(C,f,I)+z+abs(f-F));}r D[P][F][_]=R;}
L main(){cin>>n;e(i,1,n)cin>>s[i]>>t[i];cout<<S(1,1,"0000")<<endl;return 0;}
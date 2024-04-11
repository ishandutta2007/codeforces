//program 118A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  string S,Ans;cin>>S;
  for(int i=0;i<S.size();i++)
    {
      char c=(S[i]>='a')?S[i]:(S[i]+32);
      if(c!='a'&&c!='e'&&c!='i'&&c!='o'&&c!='u'&&c!='y'){Ans+='.';Ans+=c;}
    }
  cout<<Ans<<endl;
  return 0;
}
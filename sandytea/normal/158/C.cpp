//program 158C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

string Stack[10000];

int main()
{
  int N;cin>>N;
  int Top=0;
  while(N--)
    {
      string S;cin>>S;
      if(S=="pwd")
        {
          putchar('/');
          for(int i=0;i<Top;i++)cout<<Stack[i]<<'/';
          putchar('\n');
        }
      else
        {
          string T;cin>>T;
          if(T=="/")
            Top=0;
          else
            {
              int P=0;
              if(T[0]=='/'){Top=0;P=1;}
              while(P<T.size())
                {
                  string Name="";
                  while(P<T.size()&&T[P]!='/')Name+=T[P++];
                  if(Name=="..")Top--;else Stack[Top++]=Name;
                  P++;
                }
            }
        }
    }
  return 0;
}
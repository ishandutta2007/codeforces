#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;
#define MAXN 100100
map<string, vector<int> > m;
map<string, int> vis;
string input[MAXN];
string input2[MAXN];
int N, K;
int x;
int ans;
int b1, b2;
bool comp(int a, int b)
{
    return a>b;
}
string rev(string y)
{
    string p="";
    for(int i=0; i<y.length(); i++)
    {
        p.append(y.substr(y.length()-i-1, 1));
    }
    return p;
}
int main()
{
    cin>>N>>K;
    for(int i=0; i<N; i++)
    {
        cin>>input[i];
        cin>>x;
        m[input[i]].push_back(x);
    }
    sort(input, input+N);
    input2[0]=input[0];
    int counter = 1;
    for(int i=1; i<N; i++)
    {
        if(input[i]!=input[i-1])
        {
            input2[counter]=input[i];
            counter++;
        }
    }
    for(int i=0; i<N; i++)
    {
        sort(m[input2[i]].begin(), m[input2[i]].end(), comp);
    }
    int counter1=0;
    int lx;
    for(int i=0; i<counter; i++)
    {
        if(rev(input2[i])!=input2[i]&&!m[rev(input2[i])].empty()&&vis[input2[i]]==0) //while reverse isn't empty and the palindrome isn't equal
        {
            counter1=0;
            while(counter1<min((m[input2[i]]).size(), m[rev(input2[i])].size()))
            {
                lx=m[input2[i]][counter1]+m[rev(input2[i])][counter1];
                if(lx>=0)
                {
                    ans+=lx;
                    counter1++;
                    vis[input2[i]]++;
                    vis[rev(input2[i])]++;
                }
                else
                {
                    break;
                }
            }
        }
        else if(rev(input2[i])==input2[i])
        {
            counter1=0;
            while((counter1+1)<m[input2[i]].size())
            {
                lx=m[input2[i]][counter1]+m[input2[i]][counter1+1];
                if(lx>=0)
                {
                    ans+=lx;
                    counter1+=2;
                    vis[input2[i]]+=2;
                }
                else
                {
                    break;
                }
            }
        }

    }
    for(int i=0; i<counter; i++)
    {
        if(rev(input2[i])==input2[i])
        {
            if(vis[input2[i]]>0)
            b1=max(b1, -m[input2[i]][vis[input2[i]]-1]);
            if(vis[input2[i]]<m[input2[i]].size())
                b2=max(b2, m[input2[i]][vis[input2[i]]]);
        }
    }
    ans=max(ans+b1, ans+b2);
    cout<<ans<<endl;
}
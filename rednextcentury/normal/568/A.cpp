#include <bits/stdc++.h>
using namespace std;
int p[5000001];
int b[5000001];
bool pal(int i)
{
    vector<int> vec;
    while(i)
    {
        vec.push_back(i%10);
        i/=10;
    }
    for (int i=0;i<vec.size();i++)
        if (vec[i]!=vec[vec.size()-i-1])
            return 0;
    return 1;
}
int main ()
{
    ios_base::sync_with_stdio(0);
    int P,Q;
    cin>>P>>Q;
    p[1]=1;
    for (int i=2;i<=2000000;i++)
    {
        if (p[i])continue;
        for (int j=i*2;j<=2000000;j+=i)
            p[j]=1;
    }
    for (int i=1;i<=2000000;i++)
        b[i]=pal(i),p[i]=1-p[i];
    long long pr = 0;
    long long pa = 0;
    long long ret=-1;
    for (int i=1;i<=2000000;i++)
    {
        pr+=p[i];
        pa+=b[i];
        if (Q*pr<=P*pa)
        {
            ret=i;
        }
    }
    if (ret==-1)
        cout<<"Palindromic tree is better than splay tree"<<endl;
    else
        cout<<ret<<endl;
}
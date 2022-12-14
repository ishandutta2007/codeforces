#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long pos=1,neg=0;
    long long n;
    vec.push_back(1);
    while(1)
    {
        char x;
        cin>>x;
        if (x=='?')continue;
        if (x=='+')vec.push_back(1),pos++;
        else if (x=='-')vec.push_back(-1),neg++;
        else if (x=='=')
        {
            cin>>n;
            break;
        }
    }
        long long need = n - pos + neg;
        if (need<0 && -neg*(n-1)>need)
        {
            cout<<"Impossible\n";
        } else if (need<0)
        {
            cout<<"Possible"<<endl;
            need = -need;
            for (int i=0;i<vec.size();i++)
            {
                int cur = 1;
                if (vec[i]==-1)
                {
                    if (need<=n-1)cur+=need,need=0;
                    else cur+=n-1,need-=n-1;
                }
                if (i!=0)
                {
                    if (vec[i]==-1)
                        cout<<"- ";
                    else
                        cout<<"+ ";
                }
                cout<<cur<<' ';
            }
            cout<<"= "<<n<<endl;
        }
        else if (need>=0 && pos*(n-1)<need)
        {
            cout<<"Impossible\n";
        } else if (need>=0)
        {
            cout<<"Possible"<<endl;
            for (int i=0;i<vec.size();i++)
            {
                int cur = 1;
                if (vec[i]==1)
                {
                    if (need<=n-1)cur+=need,need=0;
                    else cur+=n-1,need-=n-1;
                }
                if (i!=0)
                {
                    if (vec[i]==-1)
                        cout<<"- ";
                    else
                        cout<<"+ ";
                }
                cout<<cur<<' ';
            }
            cout<<"= "<<n<<endl;
        }
}
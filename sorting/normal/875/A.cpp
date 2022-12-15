#include<iostream>
#include<vector>

using namespace std;

int sumDigits(int x)
{
    int res=0;

    while(x!=0)
    {
        res+=x%10;
        x/=10;
    }

    return res;
}

vector<int> res;

int main ()
{
    int n,i;

    cin>>n;

    for(i=1;i<n && i<=81;i++)
    {
        if(n-i+sumDigits(n-i)==n)
            res.push_back(n-i);
    }

    cout<<res.size()<<endl;

    for(i=res.size()-1;i>=0;i--)
        cout<<res[i]<<endl;

    return 0;
}
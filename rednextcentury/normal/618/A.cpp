#include <bits/stdc++.h>
using namespace std;
int ar[1000001];

int main()
{
ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    int num=1;
    ar[0]=1;
    for (int i=1;i<n;i++)
    {
        ar[num]=1;
        while(num>0 && ar[num]==ar[num-1])
        {
            ar[num-1]++;
            num--;
        }
        num++;
    }
    for (int i=0;i<num;i++)
        cout<<ar[i]<<" ";
    cout<<endl;
}
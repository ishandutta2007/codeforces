# include <iostream>
# include <stdio.h>
# include <algorithm>
# include <cmath>
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
    if (b[0]=='0' && a[0]!='0')
    {
        cout<<"WRONG_ANSWER"<<endl;
        return 0;
    }
    int n=b.length();
    for (int i=0;i<n;i++)
        for (int j=i+1;j<n;j++)
            if (b[j]<b[i] && (i>0 || b[j]>'0'))
            {
                cout<<"WRONG_ANSWER"<<endl;
                return 0;
            }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if (a!=b)
    {
        cout<<"WRONG_ANSWER"<<endl;
        return 0;
    }
    cout<<"OK"<<endl;
}
#include <iostream>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
    int n,l,r,td=0;
    cin>>n;
    vector<int>de(n);
    for(int i=0;i<n;i++){
        cin>>l>>r;
        de[i]=(l-r)*2;
        td+=l-r;
    }
    int bestn=-1,best=abs(td);
    for(int i=0;i<n;i++){
        if (abs(td-de[i])>best){
            best=abs(td-de[i]);
            bestn=i;
        }
    }
    cout<<bestn+1;
    return 0;
}
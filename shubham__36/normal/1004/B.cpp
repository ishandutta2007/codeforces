#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n,m;
    cin >> n >>m;
    int l[m],r[m];
    string s="";
    for(int i=0;i<m;i++){
        cin>>l[i] >> r[i];
    }
    for(int i=0;i<n;i++){
        if(i%2==0) s.append("0");
        else s.append("1");
    }
    cout << s << endl;
    return 0;
}
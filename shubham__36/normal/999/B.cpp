#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void mreverse(string& s,int i)
{
    string k=s;
    for(int j=0;j<i;j++){
        k[j]=s[j];
    }
    for(int j=0;j<i;j++){
        s[j]=k[i-j-1];
    }
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i=2;i<=n;i++){
        if(n%i==0){
            mreverse(s,i);
        }
    }
    cout << s;
    return 0;
}
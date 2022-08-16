#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

bool sum(string s)
{
    int temp,total=0;
    for(long long int i=s.size()-1;i>=0;i--){
        total=(total+(s[i]-'0'))%3;
        if(total==0) return true;
    }
    return false;
}

int main()
{
    string s,t,k="a";
    cin >> s;
    long long int ans=0;
    for(long long int i=s.size()-1;i>=0;i--){
        k[0]=s[i];
        t.append(k);
        if(sum(t)){
            ans++;
            t.erase();
        }
    }
    cout << ans << endl;
    return 0;
}
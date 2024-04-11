#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long long int n,k;

void iter(string& s,long long int a)
{
    for(long long int i=0;i<n;i++){
            if(k==0) break;
            if(s[i]-'a'== a){
            s[i]='1';
            k--;
        }
    }
}

int main()
{
    cin >> n >> k;
    string s;
    cin >> s;
    for(int i=0;i<26;i++){
        iter(s,i);
    }
    for(long long int i=0;i<n;i++){
        if(s[i]!='1') cout << s[i];
    }
    return 0;
}
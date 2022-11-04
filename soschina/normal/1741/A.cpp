#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string a, b;
int tier[256];

int main(){
    tier['S'] = 0;
    tier['M'] = 1;
    tier['L'] = 2;
    int n;
    scanf("%d", &n);
    while(n--){
        cin >> a >> b;
        if(a.back() != b.back())
            puts(tier[a.back()] < tier[b.back()] ? "<" : ">");
        else if(a.length() != b.length())
            puts(((a.back() == 'S') ^ (a.length() < b.length())) ? "<" : ">");
        else
            puts("=");
    }
    return 0;
}
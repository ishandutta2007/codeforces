#include <vector>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <set>
using namespace std;
int main(){
    //freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    char y[100];
    gets(y);
    set<string> a;
    for(int i=0;i<n;i++){
        char x[200];
        gets(x);
        a.insert(string(x));
    }
    cout<<a.size();
    return 0;
}
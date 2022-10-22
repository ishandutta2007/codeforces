#include <bits/stdc++.h>
using namespace std;
int n; string arr; vector <int> eight;
int main()
{
    cin>>n>>arr;
    for(int i=0;i<arr.size();i++) if(arr[i]=='8') eight.push_back(i);
    int q = (n-11)/2;
    if(q>=eight.size()) printf("NO");
    else if(eight[q]>2*q) printf("NO");
    else printf("YES");
}
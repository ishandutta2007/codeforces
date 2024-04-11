#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5;


int main()
{
    int t;
    cin >> t;
    while(t--) {
        int i,j,n,k;
        scanf("%d %d", &n ,&k);
        int x=n/k;
        for(i=0; i<k; i++) {
            for(j=0; j<x; j++) {
                printf("%c", 'a'+i);
            }
            if(n%k>i) printf("%c", 'a'+i);
        }
        puts("");
    }
}
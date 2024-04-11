#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int n,k;
    int num[1005];
    scanf("%d%d", &n,&k);
    for(int i = 1; i <= n; i++) scanf("%d", &num[i]);
    int pos = k;
    while(num[pos] != 1) {
    	pos++;
    	if(pos > n) pos = 1;
//        pos++;
//        pos = (pos - 1) % n + 1;
    }
    cout << pos;
}
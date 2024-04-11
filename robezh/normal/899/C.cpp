#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

int n;
vector<int> res;

int main() {
    cin >> n;
    if(n % 4 == 0) {
        printf("0\n");
        for(int i = 1; i <= n; i++) {
            if(i <= n/4 || i > n/4*3) res.push_back(i);
        }
    } else if(n % 4 == 3) {
    	printf("0\n");
        for(int i = 1; i <= n; i++) {
            if(i < (n+1)/4 || i >= (n+1)/4*3) res.push_back(i);
        }
    } else if(n % 4 == 2) {
    	printf("1\n");
        for(int i = 1; i <= n; i++) {
            if((i+2) <= (n+2)/4 || (i+2) > (n+2)/4 * 3) {
                res.push_back(i);
            }
        }
    } else {
        printf("1\n");
        for(int i = 2; i <= n; i++) {
            if((i-1) <= (n-1)/4 || (i-1) > (n-1)/4 * 3) {
                res.push_back(i);
            }
        }
    }
    
    printf("%d ", res.size());
    for(int i = 0; i < res.size(); i++) printf("%d ", res[i]);
}
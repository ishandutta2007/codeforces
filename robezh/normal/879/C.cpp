#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;


int digit[15];
bool zero[10];
bool ones[10];

int main() {
    int n;
    char a;
    int b;
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < 10; i++) {
        zero[i] = false;
        ones[i] = false;
        digit[i] = 0;
    }

    for(int i = 0; i < n; i++) {

        cin>>a>>b;

        for(int i = 0; i < 10; i++) {
            int r = b % 2;
            b = b / 2;
            if(a == '&' & r == 0) {
                digit[i] = 0;
                zero[i] = true;
                ones[i] = false;
            } else if((a == '&' && r == 1) || (a == '|' && r == 0) || (a == '^' && r == 0)) {
                continue;
            } else if((a == '|' && r == 1)) {
                digit[i] = 0;
                ones[i] = true;
                zero[i] = false;
            } else if(a == '^' && r == 1) {
                digit[i] = 1 - digit[i];
            }
        }
    }
    int xornum = 0;
    int andnum = 1023;
    int ornum = 0;
    int multi = 1;
    for(int i = 0; i < 10; i++) {
    	if(ones[i] == true){
    		ornum += multi;
		}
		else if(zero[i] == true){
			andnum -= multi;
		}
		xornum += digit[i] * multi;
		multi *= 2;
    }
    int count = 0;
    if(xornum > 0) count++;
    if(andnum < 1023) count++;
    if(ornum > 0) count++;
    printf("%d\n", count);
    if(andnum < 1023) printf("& %d\n", andnum);
    if(ornum > 0) printf("| %d\n", ornum);
    if(xornum > 0) printf("^ %d\n", xornum);

}
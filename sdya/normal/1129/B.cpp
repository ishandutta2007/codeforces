#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#include <list>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int B = 1000000;

void output(int a, int b, int c, int n1, int n2, int n3) {
    printf("%d\n", n1 + n2 + n3);
    for (int i = 0; i < n1; ++i) {
        printf("%d ", (i == 0 ? a : 0));
    }
    printf("%d ", -c + n3 - 1);
    for (int i = 1; i < n3; ++i) {
        printf("-1 ");
    }
    for (int i = 0; i < n2; ++i) {
        printf("%d ", (i == 0 ? b : 0));
    }
    printf("\n");
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int k;
	cin >> k;
	
	if (k <= 1000) {
	    for (int n1 = 1; n1 <= 2000; ++n1) {
            for (int n2 = 1; n1 + n2 + 1 <= 2000; ++n2) {
                for (int n3 = 1; n3 <= 10 && n1 + n2 + n3 <= 2000; ++n3) {
                    for (int a = k / (n2 + n3); a >= 1; --a) {
                        int v = k - a * (n2 + n3);
                        if (v > 5000) break;
                        if (v % (n1 + n2 + n3) == 0) {
                            int u = v / (n1 + n2 + n3);
                            int c = (a + n3);
                            int b = u + c;
                            if (b * n2 > a * n1) {
                                break;
                            }
                            if (c <= B && b <= B) {
                                output(a, b, c, n1, n2, n3);
                                return 0;
                            }
                        }
                    }
                }
            }
        }
	} else {
        for (int n2 = 1; n2 <= 2000; ++n2) {
            for (int n3 = 1; n3 <= 40 && n2 + n3 <= 2000; ++n3) {
                for (int a = k / (n2 + n3); a >= 1; --a) {
                    int v = k - a * (n2 + n3);
                    if (v > 5000) break;
                    for (int u = 1; u <= 10; ++u) {
                        if (v % u != 0 || v / u > 2000) {
                            continue;
                        }
                        int n1 = v / u - n2 - n3;
                        if (n1 < 1) continue;
                        
                        int c = (a + n3);
                        int b = u + c;
                        if (b * n2 > a * n1) {
                            break;
                        }
                        if (c <= B && b <= B) {
                            output(a, b, c, n1, n2, n3);
                            return 0;
                        }
                    }
                }
            }
        }
	}
	printf("3\n-1 1 3\n");

	return 0;
}
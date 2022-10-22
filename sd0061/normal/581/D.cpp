#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
typedef long long LL;
using namespace std;
const int N = 100005;
int x[3] , y[3];

void work() {
    int area = 0;
    for (int i = 0 ; i < 3 ; ++ i) {
        cin >> x[i] >> y[i];
        if (x[i] > y[i])
            swap(x[i] , y[i]);
        area += x[i] * y[i];
    }
    int l = 0;
    while (l * l < area) ++ l;
    if (l * l != area) {
        puts("-1");
    } else {
        if (y[0] == y[1] && y[1] == y[2] && y[2] == l && x[0] + x[1] + x[2] == l) {
            printf("%d\n" , l);
            for (int k = 0 ; k < 3 ; ++ k) {
                for (int i = 0 ; i < x[k] ; ++ i) {
                    for (int j = 0 ; j < l ; ++ j) {
                        putchar('A' + k);
                    }
                    puts("");
                }
            }
        } else {
            for (int i = 0 ; i < 3 ; ++ i) {
                if (y[i] == l) {
                    for (int j = 0 ; j < 3 ; ++ j)
                        if (j != i)
                            for (int k = 0 ; k < 3 ; ++ k) {
                                if (k != i && k != j) {
                                    int p = l - x[i];
                                    for (int w = 1 ; w < l ; ++ w) {
                                        int a = w , b = l - w;
                                        if (x[j] == p && y[j] == a || x[j] == a && y[j] == p) {
                                            if (x[k] == p && y[k] == b || x[k] == b && y[k] == p) {
                                                printf("%d\n" , l);
                                                for (int X = 0 ; X < x[i] ; ++ X) {
                                                    for (int Y = 0 ; Y < l ; ++ Y) 
                                                        putchar('A' + i);
                                                    puts("");
                                                }
                                                for (int X = 0 ; X < p ; ++ X) {
                                                    for (int Y = 0 ; Y < a ; ++ Y) 
                                                        putchar('A' + j);
                                                    for (int Y = 0 ; Y < b ; ++ Y) 
                                                        putchar('A' + k);
                                                    puts("");
                                                }
                                                return;
                                            }
                                            
                                        }


                                        
                                    }
                                    

                                    
                                }
                            }

                }
            }
            puts("-1");
        }
    }
}

int main() {
    work();
    return 0;
}
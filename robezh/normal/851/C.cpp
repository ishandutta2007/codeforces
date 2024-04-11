#include<cstdio>
using namespace std;

int n;
int dim[1005][5];
bool good[1005];
int count;

int times(int ind, int index1, int index2) {
    int sum = 0;
    for(int i = 0; i < 5; i++) {
        sum += (dim[index1][i] - dim[ind][i]) * (dim[index2][i] - dim[ind][i]);
    }
    return sum;
}

int main() {
    scanf("%d", &n);
    count = n;
    for(int i = 0; i < n; i++) {
        good[i] = true;
        for(int j = 0; j < 5; j++) {
            scanf("%d", &dim[i][j]);
        }
    }
    for(int i = 0; i < n; i++) {
        if(good[i]) {
            for(int j = 0; j < n; j++) {
                if(j != i && good[i]) {
                    for(int k = 0; k < n; k++) {
                        if(k != i && k != j && good[i]) {
                            if(times(i, j, k) > 0) {
                                if(good[i]) {
                                    good[i] = false;
                                    //printf("times(%d %d %d) = %d\n", i,j,k,times(i,j,k));
                                    //printf("So good[%d] = false\n", i);
                                    count--;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", count);
    for(int i = 0; i < n; i++) {
        if(good[i]) {
        	printf("%d\n", i + 1);
        }
    }
}
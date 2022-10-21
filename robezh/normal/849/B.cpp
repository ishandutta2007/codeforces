#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

int nums[1005];
int n;

bool inaline(int num1, int num2, double k) {
    if(abs((nums[num2] - nums[num1]) / (double)(num2 - num1) - k)< 0.0001) {
        return true;
    } else {
        return false;
    }
}

int main() {
    bool ans = false;
    bool status;
    double k1, k2;
    bool updated;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    for(int i = 0; i < 3; i++) {
        updated = false;
        status = true;
        int a = (i==0 ? 1 : 0);
        int b = (a==1 ? 2 : 3 - i);
        int c = 3 - a - b;
        //printf("a = %d,b = %d\n", a,b);
        //cout<<(double)(nums[b] - nums[a])<<endl;
        //cout<<(double)(b-a)<<endl;
        k1 = double(nums[b] - nums[a]) / double(b-a);
        if(inaline(a,c,k1)) {
            status = false;
            for(int j = 3; j < n; j++) {
                if(!inaline(a, j, k1)) {
                    c = j;
                    status = true;
                    break;
                }
            }
        }
        //printf("k1 = %lf\n", k1);
        //printf("nums[%d] and nums[%d] in a line\n", a, b);
        for(int j = 3; j < n; j++) {
            if(j != c) {
                //printf("k1 = %lf , nums[%d] and num[%d] in a line : %d\n", k1, a, j,inaline(a,j,k1)  );
                if(updated) {
                    //printf("k2 = %lf, nums[%d] and num[%d] in a line : %d\n", k2, c, j,inaline(c,j,k2)  );
                }
                if(!inaline(a,j,k1)) {
                    if(!updated) {
                        k2 = (nums[j] - nums[c]) / (double)(j - c);
                        if(abs(k2 - k1) > 0.0001) {
                            status = false;
                            break;
                        }
                        updated = true;
                    }
                    if(!inaline(c,j,k2)) {
                        status = false;
                        break;
                    }
                }
            }
        }
        //printf("status == %d\n", status);
        if(status) {
            ans = true;
            break;
        }
    }
    if(ans) printf("Yes");
    else printf("No");

}
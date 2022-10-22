#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long LL;

#define N 20005
#define M 2000005
using namespace std;

int A , B;
int SQR[M];
vector< pair<int , int> > a , b;
int S(int x) {
    return x * x;
}

void work()
{
    int i , j , k;
    memset(SQR , -1 , sizeof(SQR));
    for (i = 0 ; i * i <= 2000000 ; ++ i)
        SQR[i * i] = i;
    cin >> A >> B;
    for (i = 1 ; i * i < A * A ; ++ i) {
        if (~SQR[A * A - i * i]) {
            j = SQR[A * A - i * i];
            a.push_back(make_pair(i , j));
        }
    }
    for (i = 1 ; i * i < B * B ; ++ i) {
        if (~SQR[B * B - i * i]) {
            j = SQR[B * B - i * i];
            b.push_back(make_pair(i , j));
        }
    }
    for (i = 0 ; i < a.size() ; ++ i)
        for (j = 0 ; j < b.size() ; ++ j) {
            if (S(a[i].first + b[j].first) + S(a[i].second + b[j].second) == A * A + B * B) {
                puts("YES");
                printf("0 0\n");
                printf("%d %d\n" , a[i].first , a[i].second);
                printf("%d %d\n" , -b[j].first , -b[j].second);
                return;
            }
            if (S(a[i].first + b[j].first) + S(a[i].second - b[j].second) == A * A + B * B && a[i].second != b[j].second) {
                puts("YES");
                printf("0 0\n");
                printf("%d %d\n" , a[i].first , a[i].second);
                printf("%d %d\n" , -b[j].first , b[j].second);
                return;
            }
            if (S(a[i].first - b[j].first) + S(a[i].second + b[j].second) == A * A + B * B && a[i].first != b[j].first) {
                puts("YES");
                printf("0 0\n");
                printf("%d %d\n" , a[i].first , a[i].second);
                printf("%d %d\n" , b[j].first , -b[j].second);
                return;
            }
            if (S(a[i].first - b[j].first) + S(a[i].second - b[j].second) == A * A + B * B && a[i].second != b[j].second && a[i].first != b[j].first) {
                puts("YES");
                printf("0 0\n");
                printf("%d %d\n" , a[i].first , a[i].second);
                printf("%d %d\n" , b[j].first , b[j].second);
                return;
            }
        }
    puts("NO");

}


int main()
{
    //freopen("1.txt" , "r" , stdin);
    work();
    return 0;
}
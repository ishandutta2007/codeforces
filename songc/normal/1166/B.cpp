#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int N;
char ch[5] = {'a', 'e', 'i', 'o', 'u'};

int main(){
    scanf("%d", &N);
    for (int i=5; N/i >= 5; i++){
        if (N % i == 0){
            for (int j=1; j<=i; j++) for (int k=1; k<=N/i; k++) printf("%c", ch[(j+k)%5]);
            return 0;
        }
    }
    puts("-1");
    return 0;
}
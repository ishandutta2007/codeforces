#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int N = 300002;
int t;
char s[N];
int main() {
    scanf("%d", &t);
    while (t --) {
        scanf("%s", s+1);
        queue<char> q1,q2;
        for (int i=1;s[i];i++) {
            if ((s[i] - '0') % 2 == 0) q1.push(s[i]);
            else q2.push(s[i]);
        }
        while (q1.size() || q2.size()) {
            if (q1.size() == 0) {
                printf("%c", q2.front()); q2.pop(); continue;
            }
            if (q2.size() == 0) {
                printf("%c", q1.front()); q1.pop();  continue;
            }
            if (q1.front() < q2.front()) {
                printf("%c", q1.front()); q1.pop(); 
            } else {
                printf("%c", q2.front()); q2.pop();
            }
        }
        printf("\n");
    }
}
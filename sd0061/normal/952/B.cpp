#include <bits/stdc++.h>
using namespace std;
const int N = 55;

char str[N];

int main() {
    srand(time(0));
    set<string> h;
    int a[10] = {0 , 1 , 2 , 3 ,4 ,5 ,6 ,7 ,8 ,9};
    random_shuffle(a , a + 10);
    while (1) {
        for (int i = 0 ; i < 1 ; ++ i) {
            printf("%d\n" , rand() % 10);
            fflush(stdout);
            scanf("%s" , str);
            //h.insert(str);

            if (strstr(str, "bad") || strstr(str, "cool") || strstr(str, "great") ||
                strstr(str, "touch") || strstr(str, "think")) {
                puts("normal");
                return 0;
            }

            if (strstr(str, "even") || strstr(str, "worse") || strstr(str, "hole") ||
                strstr(str, "torr") || strstr(str, "ser") || strstr(str , "way")) {
                puts("grumpy");
                return 0;
            }

        }
        //puts(!h.count("great!") ? "grumpy" : "normal");
    }
}
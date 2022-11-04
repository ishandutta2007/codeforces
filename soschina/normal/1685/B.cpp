#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 2e5 + 2;

int t, n, a, b, c, d, cnt, cnta, cntb;
char s[N];

vector<int> lena, lenb;

int main(){
	scanf("%d", &t);
    while(t--){
        cnt = 0;
        cnta = 0;
        cntb = 0;
        lena.clear();
        lenb.clear();
        scanf("%d%d%d%d%s", &a, &b, &c, &d, s + 1);
        n = strlen(s + 1);
        for (int i = 1; i <= n; i++){
            if(s[i] == 'A')
                cnta++;
            else
                cntb++;
        }
        if(cnta != a + c + d){
            puts("NO");
            continue;
        }
        char first = s[1];
        int len = 1;
        for (int i = 2; i <= n; i++){
            if(s[i] != s[i - 1])
                len++;
            else{
                if(len & 1){
                    cnt += len / 2;
                }else{
                    if(first == 'A'){
                        lena.push_back(len / 2);
                    }else{
                        lenb.push_back(len / 2);
                    }
                }
                first = s[i];
                len = 1;
            }
        }
        if(len & 1){
            cnt += len / 2;
        }else if(first == 'A'){
            lena.push_back(len / 2);
        }else{
            lenb.push_back(len / 2);
        }
        sort(lena.begin(), lena.end());
        sort(lenb.begin(), lenb.end());
        for(int len : lena){
            int delta = min(len, c);
            c -= delta;
            delta = max(0, min(len - delta - 1, d));
            d -= delta;
        }
        for(int len : lenb){
            int delta = min(len, d);
            d -= delta;
            delta = max(0, min(len - delta - 1, c));
            c -= delta;
        }
        if(cnt >= c + d)
            puts("YES");
        else
            puts("NO");
    }
	return 0;
}
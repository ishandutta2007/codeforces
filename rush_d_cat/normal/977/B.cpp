#include <iostream>
using namespace std;
const int N = 102;

int n;
char s[N];

int main() {
    scanf("%d %s",&n,s+1);
    
    int bst=0;
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            int cnt=0;
            for(int k=1;k<n;k++){
                if(s[k]=='A'+i && s[k+1]=='A'+j) cnt++;
            }
            if(cnt>bst)
            bst=cnt;
        }
    }

    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            int cnt=0;
            for(int k=1;k<n;k++){
                if(s[k]=='A'+i && s[k+1]=='A'+j) cnt++;
            }
            if(cnt==bst) {
                printf("%c%c\n", 'A'+i,'A'+j);
                return 0;
            }
        }
    }
}
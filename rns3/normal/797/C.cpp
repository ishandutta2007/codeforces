#include<bits/stdc++.h>
using namespace std;

const int N = 100005;

stack<char> st;
int n;
char s[N], a[N];

int main(){
	gets(s);
    n = strlen(s);
    a[n] = 'z' + 1;
    for(int i = n - 1; i >= 0; --i) a[i] = min(s[i], a[i+1]);
    for(int i = 0; i < n; i ++){
        st.push(s[i]);
        while(!st.empty() && st.top() <= a[i+1]) {
            printf("%c",st.top());
            st.pop();
        }
    }
    return 0;
}
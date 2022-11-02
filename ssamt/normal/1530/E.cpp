#include <stdio.h>
#include <stdlib.h>
#include <vector>

int main() {
	int h, i, j;
	int t, n;
	char s[100001];
	int c[26];
	int type;
	std::vector<int> let;
	char answer[100001];
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%s", s);
		for(i=0; s[i]; i++);
		n = i;
		for(i=0; i<26; i++) {
			c[i] = 0;
		}
		for(i=0; i<n; i++) {
			c[s[i]-'a']++;
		}
		type = 0;
		let.clear();
		for(i=0; i<26; i++) {
			if(c[i] > 0) {
				type++;
				let.push_back(i);
			}
		}
		if(type == 1) {
			for(i=0; i<n; i++) {
				answer[i] = let[0]+'a';
			}
		} else if(type == 2) {
			for(i=0; i<26 && c[i]!=1; i++);
			if(i == 26) {
				if(c[let[0]] <= n/2+1) {
					answer[0] = let[0]+'a';
					for(i=1; i<n; i++) {
						if(i%2 == 0 || (i+1)/2 >= c[let[0]]) {
							answer[i] = let[1]+'a';
						} else {
							answer[i] = let[0]+'a';
						}
					}
				} else {
					answer[0] = let[0]+'a';
					for(i=1; i<c[let[1]]+1; i++) {
						answer[i] = let[1]+'a';
					}
					for(i=c[let[1]]+1; i<n; i++) {
						answer[i] = let[0]+'a';
					}
				}
			} else {
				answer[0] = i+'a';
				int skip = i;
				int idx = 1;
				for(i=0; i<type; i++) {
					if(let[i] != skip) {
						for(j=0; j<c[let[i]]; j++, idx++) {
							answer[idx] = let[i]+'a';
						}
					}
				}
			}
		} else {
			for(i=0; i<26 && c[i]!=1; i++);
			if(i == 26) {
				if(c[let[0]] <= n/2+1) {
					std::vector<char> temp;
					temp.push_back(let[0]+'a');
					temp.push_back(let[0]+'a');
					int count = 2;
					for(i=1; i<type; i++) {
						for(j=0; j<c[let[i]]; j++, count++) {
							temp.push_back(let[i]+'a');
							if(count < c[let[0]]) {
								temp.push_back(let[0]+'a');
							}
						}
					}
					for(i=0; i<n; i++) {
						answer[i] = temp[i];
					}
				} else {
					answer[0] = let[0]+'a';
					answer[1] = let[1]+'a';
					c[let[1]]--;
					for(i=2; i<c[let[0]]+1; i++) {
						answer[i] = let[0]+'a';
					}
					answer[c[let[0]]+1] = let[2]+'a';
					c[let[2]]--;
					int idx = c[let[0]]+2;
					for(i=1; i<type; i++) {
						for(j=0; j<c[let[i]]; j++, idx++) {
							answer[idx] = let[i]+'a';
						}
					}
				}
			} else {
				answer[0] = i+'a';
				int skip = i;
				int idx = 1;
				for(i=0; i<type; i++) {
					if(let[i] != skip) {
						for(j=0; j<c[let[i]]; j++, idx++) {
							answer[idx] = let[i]+'a';
						}
					}
				}
			}
		}
		answer[n] = '\0';
		printf("%s\n", answer);
	}
}
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>

int main() {
	int h, i, j, k;
	int t, n;
	int start, end;
	char s[500000+1];
	char init[500000+1];
	int count[26];
	int total[26];
	std::vector<char> order;
	int idx;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		int found = 0;
		scanf("%s", s);
		for(i=0; s[i]; i++);
		n = i;
		for(j=0; j<26; j++) {
			count[j] = 0;
			total[j] = 0;
		}
		for(i=0; i<n; i++) {
			total[s[i]-'a']++;
		}
		count[s[0]-'a']++;
		for(i=1; i<n; i++) {
			int check = 1;
			for(j=0; j<26; j++) {
				if((count[j] != 0 && total[j]%count[j] != 0) || (count[j] == 0 && total[j] != 0)) {
					check = 0;
					break;
				}
			}
			if(check) {
				order.clear();
				start = 0;
				end = i;
				while(start < n) {
					int found2 = 0;
					for(j=0; j<26; j++) {
						int found3 = 0;
						for(k=start; k<end; k++) {
							if(s[k] == j+'a') {
								found3 = 1;
								break;
							}
						}
						if(found3) {
							idx = end;
							for(k=start; k<end; k++) {
								if(s[k] != j+'a') {
									if(s[k] != s[idx]) {
										break;
									}
									idx++;
								}
							}
							if(k == end) {
								if(end == idx && end != n) {
									break;
								}
								order.push_back(j+'a');
								found2 = 1;
								start = end;
								end = idx;
								break;
							}
						}
					}
					if(!found2) {
						break;
					}
				}
				if(start == n) {
					for(j=0; j<i; j++) {
						init[j] = s[j];
					}
					init[i] = '\0';
					found = 1;
					break;
				}
			}
			count[s[i]-'a']++;
		}
		int same = 1;
		for(i=1; i<n; i++) {
			if(s[0] != s[i]) {
				same = 0;
				break;
			}
		}
		if(same) {
			printf("%s %c\n", s, s[0]);
		} else if(found) {
			printf("%s ", init);
			for(i=0; i<order.size(); i++) {
				printf("%c", order[i]);
			}
			printf("\n");
		} else {
			printf("-1\n");
		}
	}
}
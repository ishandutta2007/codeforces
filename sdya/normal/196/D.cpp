#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <cmath>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 500000;
const long long P = 137LL;

char s[maxN];
int n, d;

int calculatePrefix() {
	vector < long long > hash(maxN, 0LL);
	vector < long long > reversed_hash(maxN, 0LL);

	vector < long long > powers(maxN, 1LL);

	for (int i = 1; i < maxN; ++i) {
		powers[i] = powers[i - 1] * P;
	}

	long long current_hash = 0;
	for (int i = 0; i < n; ++i) {
		current_hash = current_hash * P + (s[i] - 'a' + 1);
		hash[i] = current_hash;
	}
	current_hash = 0;
	for (int i = n - 1; i >= 0; --i) {
		current_hash = current_hash * P + (s[i] - 'a' + 1);
		reversed_hash[i] = current_hash;
	}

	int result = -1;

	for (int i = 0; i < n; ++i) {
		bool possible_to_continue = false;
		for (int j = s[i]; j <= 'z'; ++j) {
			bool good_first = true, good_second = true;
			{
				int l = i - d + 1, r = i;
				if (l >= 0) {
					bool is_palindrome = false;
					if (l + 1 <= r - 1) {
						long long right_hash = hash[r - 1] - hash[l] * powers[r - l - 1];
						long long left_hash = reversed_hash[l + 1] - reversed_hash[r] * powers[r - l - 1];
						if (left_hash == right_hash) {
							is_palindrome = true;
						}
					} else {
						is_palindrome = true;
					}
					if (is_palindrome && s[l] == j) {
						good_first = false;
					}
				}
			}

			{
				int l = i - d, r = i;
				if (l >= 0) {
					bool is_palindrome = false;
					if (l + 1 <= r - 1) {
						long long right_hash = hash[r - 1] - hash[l] * powers[r - l - 1];
						long long left_hash = reversed_hash[l + 1] - reversed_hash[r] * powers[r - l - 1];
						if (left_hash == right_hash) {
							is_palindrome = true;
						}
					} else {
						is_palindrome = true;
					}
					if (is_palindrome && s[l] == j) {
						good_second = false;
					}
				}
			}

			if (good_first && good_second) {
				if (j == s[i]) {
					possible_to_continue = true;
				} else {
					result = i;
					break;
				}
			}
		}
		if (!possible_to_continue) {
			break;
		}
	}

	return result;
}

void printAnswer(int prefix) {
	vector < long long > hash(maxN, 0LL);
	vector < long long > reversed_hash(maxN, 0LL);

	vector < long long > powers(maxN, 1LL);

	for (int i = 1; i < maxN; ++i) {
		powers[i] = powers[i - 1] * P;
	}

	long long current_hash = 0;
	for (int i = 0; i < n; ++i) {
		current_hash = current_hash * P + (s[i] - 'a' + 1);
		hash[i] = current_hash;
	}

	long long add = 0, coefficient = 1LL;

	for (int i = 0; i < n; ++i, coefficient *= P) {
		int left_bound = 'a', right_bound = 'z';
		if (i < prefix) {
			left_bound = right_bound = s[i];
		} else if (i == prefix) {
			left_bound = s[i] + 1;
		}
		for (int j = left_bound; j <= right_bound; ++j) {
			reversed_hash[i] = add + (long long)(j - 'a' + 1) * coefficient;
			hash[i] = (j - 'a' + 1);
			if (i != 0) {
				hash[i] += hash[i - 1] * P;
			}
			bool good_first = true, good_second = true;

			{
				int l = i - d + 1, r = i;
				if (l >= 0) {
					bool is_palindrome = false;
					if (l + 1 <= r - 1) {
						long long right_hash = hash[r - 1] - hash[l] * powers[r - l - 1];
						long long left_hash = reversed_hash[r - 1] - reversed_hash[l];
						if (left_hash == right_hash * powers[l + 1]) {
							is_palindrome = true;
						}
					} else {
						is_palindrome = true;
					}
					if (is_palindrome && s[l] == j) {
						good_first = false;
					}
				}
			}

			{
				int l = i - d, r = i;
				if (l >= 0) {
					bool is_palindrome = false;
					if (l + 1 <= r - 1) {
						long long right_hash = hash[r - 1] - hash[l] * powers[r - l - 1];
						long long left_hash = reversed_hash[r - 1] - reversed_hash[l];
						if (left_hash == right_hash * powers[l + 1]) {
							is_palindrome = true;
						}
					} else {
						is_palindrome = true;
					}
					if (is_palindrome && s[l] == j) {
						good_second = false;
					}
				}
			}

			if (good_first && good_second) {
				s[i] = j;
				add += (long long)(j - 'a' + 1) * coefficient;
				break;
			}
		}
	}

	puts(s);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d\n", &d);
	gets(s);
	n = strlen(s);

	int prefix = calculatePrefix();
	if (prefix == -1 || d == 1) {
		printf("Impossible\n");
	} else {
		printAnswer(prefix);
	}

	return 0;
}
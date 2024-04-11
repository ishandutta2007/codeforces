#include <cstdio>
#include <algorithm>
#include <deque>
#include <unordered_map>
using namespace std;
int main() {
	int n, k, id;
	scanf("%d %d", &n, &k);
	deque<int> messages;
	unordered_map<int, int> friends;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &id);
		if (friends.find(id) != friends.end()) continue;
		else {
			if (messages.size() == k) {
				friends[messages.front()] -= 1;
				if (friends[messages.front()] == 0) friends.erase(messages.front());
				messages.pop_front();
			}
			messages.push_back(id);
			friends[id] += 1;
		}
	}
	reverse(messages.begin(), messages.end());
	printf("%lu\n", messages.size());
	for (int i: messages) printf("%d ", i);
	return 0;
}
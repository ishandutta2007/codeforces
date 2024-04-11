from collections import deque
n = int(input())
s = input()
ans = deque()
for i in range(n):
    if i % 2 != n % 2:
        ans.append(s[i])
    else:
        ans.appendleft(s[i])
print(''.join(list(ans)))
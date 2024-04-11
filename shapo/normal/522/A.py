#!/usr/bin/env python3.4

n = int(input())
ans = {'polycarp':1}
for i in range(n):
    repost, _, reposted = input().lower().split()
    ans[repost] = ans[reposted] + 1
print(max(ans.values()))
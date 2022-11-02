_ = raw_input()
a = map(int, raw_input().split())
cost = map(int, raw_input().split())
cost.reverse()

cur = 0
ans = [0] * 5
for item in a:
    cur += item
    for i, z in enumerate(cost):
        ans[i] = ans[i] + cur / z
        cur = cur % z

print " ".join(map(str, reversed(ans)))
print cur
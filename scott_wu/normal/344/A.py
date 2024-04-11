a = int(input())
last = "11"
ans = 0

for i in range(a):
    nval = raw_input()
    if nval != last:
        ans += 1
    last = nval
print ans
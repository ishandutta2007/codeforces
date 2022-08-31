a,b = (int(s) for s in raw_input().split())
left,ans = 0,0

while a > 0:
    a -= 1
    ans += 1
    left += 1
    if left == b:
        left = 0
        a += 1
print ans
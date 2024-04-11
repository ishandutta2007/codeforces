n = int(input())
ans = 0
def check(k):
    global n
    if k == n: return False
    k = str(k)
    for i in k:
        if i == '8': return True
    return False
a = n
while not check(a):
    a += 1
    ans += 1
print(ans)
def right_m(me, num):
    k = min(me, num)
    return k * (k + 1) // 2
def left_m(me, num):
    k = me
    if me <= num:
        return k * (k + 1) // 2
    l = me - num
    return k * (k + 1) // 2 - l * (l + 1) // 2
def ans(lm, rm, num):
    if num <= lm:
        return left_m(lm, num)
    ans = right_m(rm, num)
    num -= rm
    if num > 0:
        ans += left_m(lm, num)
    return ans
n, x = map(int, input().split())
lst = list(map(int,input().split()))
daysnum = [0] * n * 2
ansnum = [0] * n * 2
daysnum[0] = lst[0]
ansnum[0] = (lst[0] + 1) * lst[0] // 2
for i in range(1, 2 * n):
    daysnum[i] = daysnum[i-1] + lst[i%n]
    ansnum[i] = ansnum[i-1] + (lst[i%n] + 1) * lst[i%n] // 2
leftnum = 0
rightnum = 1
maxans = 0
while leftnum < n and rightnum < 2 * n:
    if leftnum == rightnum:
        rightnum += 1
        continue
    ihave = x - daysnum[rightnum - 1] + daysnum[leftnum]
    if ihave < 0:
        leftnum += 1
        continue
    ansnow = ansnum[rightnum - 1] - ansnum[leftnum]
    ansnow += ans(lst[leftnum%n], lst[rightnum%n], ihave)
    maxans = max(maxans, ansnow)
    rightnum += 1
print(maxans)
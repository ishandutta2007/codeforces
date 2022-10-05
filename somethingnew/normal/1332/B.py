from math import sqrt
def delit(a, prost1):
    deli = []
    for i in range(2, int(sqrt(a)) + 1):
        if a % i == 0:
            deli.append(prost1[i])
            while a % i == 0:
                a //= i
    return deli
prost = dict(zip([2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499], range(95)))
for ktirs in range(int(input())):
    n = int(input())
    nums = []
    for i in range(95):
        nums.append([])
    pos = -1
    for i in list(map(int, input().split())):
        pos += 1
        k = delit(i, prost)
        for j in k:
            nums[j].append(pos)
    ans = [0] * n
    num = 1
    for j in range(11):
        tr = False
        for i in nums[j]:
            if ans[i] == 0:
                ans[i] = num
                tr = True
        num += tr
    print(num - 1)
    print(*ans)
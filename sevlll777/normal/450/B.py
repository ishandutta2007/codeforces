x, y = map(int, input().split())
n = int(input())
hop = [x, y, y - x, -x, -y, x - y]
n %= 6
print(hop[n - 1] % (10 ** 9 + 7))
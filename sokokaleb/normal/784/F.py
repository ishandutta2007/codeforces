arr = input().split()[1:]
import time
current_milli_time = lambda: int(round(time.time() * 1000))
s = current_milli_time()
for i in range(len(arr)):
    for j in range(len(arr) - i - 1):
        if int(arr[j]) > int(arr[j + 1]):
            arr[j], arr[j + 1] = arr[j + 1], arr[j]
while current_milli_time() - s <= 1.5 * 1000:
    pass
print(' '.join(arr))
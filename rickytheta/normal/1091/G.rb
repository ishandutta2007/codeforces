def modpow(a,b,m)
  r = 1
  while b > 0
    r = r * a % m if b % 2 == 1
    a = a * a % m
    b >>= 1
  end
  return r
end

def isprime(n)
  return true if n == 2
  return false if n == 1 || n & 1 == 0
  d = n-1
  d >>= 1 while d & 1 == 0
  20.times do
    a = rand(n-2) + 1
    t = d
    y = modpow(a,t,n)
    while t != n-1 && y != 1 && y != n-1
      y = (y * y) % n
      t <<= 1
    end
    return false if y != n-1 && t & 1 == 0
  end
  return true
end

def solve(n,gn)
  # puts "solve #{n}"
  while true
    x = rand(1...n)
    x2 = x * x % gn
    puts "sqrt #{x2}"
    STDOUT.flush
    y = gets.chomp.to_i % n
    next if x == y
    gg = x - y
    gg = -gg if gg < 0
    q = n.gcd(gg)
    next if q == 1 or q == n
    # ok
    ret = []
    if isprime(q)
      ret.push(q)
    else
      ret = solve(q,gn)
    end
    q = n/q
    if isprime(q)
      ret.push(q)
    else
      ret.concat(solve(q,gn))
    end
    return ret
  end
end

n = gets.chomp.to_i
ans = solve(n,n)
ansstr = "! #{ans.length} #{ans.join(' ')}"
puts ansstr
STDOUT.flush
def solve(p,k)
  b = [1]
  l = [0]
  r = [k]
  while true
    bb = b.last
    nb = -k*bb
    b.push(nb)
    if nb > 0
      r.push(r.last + (k-1)*nb)
      l.push(l.last)
    else
      l.push(l.last + (k-1)*nb)
      r.push(r.last)
    end
    break if p < r.last
  end

  ans = []
  while b.length > 1
    l.pop
    r.pop
    bb = b.pop
    le = l.last
    ri = r.last
    i = 0
    while !(le <= p && p < ri)
      p -= bb
      i += 1
    end
    ans.push(i)
  end
  ans.push(p)
  ans.reverse!
  while ans.last == 0
    ans.pop
  end
  return ans
end

p, k = gets.chomp.split
p = p.to_i
k = k.to_i
ans = solve(p,k)
puts(ans.length)
puts(ans.join(" "))
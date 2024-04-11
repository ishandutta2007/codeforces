const gets = (() => {
  const lines = [];

  require("readline")
    .createInterface({
      input: process.stdin,
      output: process.stdout
    })
    .on("line", line => {
      if (lines.length > 0 && typeof lines[0] === "function") {
        lines.shift()(line);
      } else {
        lines.push(line);
      }
    });

  return async () => {
    if (lines.length > 0 && typeof lines[0] === "string") {
      return lines.shift();
    }
    return new Promise(resolve => lines.push(resolve));
  };
})();

const get_nums = async () => (await gets()).split(" ").map(x => Number(x));

function build(a) {
  const n = a.length;
  const s = new Array(n + 1);
  s.fill(0);
  let c = 0;
  for (let i = 0; i < n; i++) {
    if (a[i] === 0) {
      c = 0;
    } else {
      c++;
      s[c]++;
    }
  }
  for (let i = n - 1; i >= 0; i--) {
    s[i] += s[i + 1];
  }
  return s;
}

async function main() {
  const [n, m, k] = await get_nums();
  const a = await get_nums();
  const b = await get_nums();
  const sa = build(a);
  const sb = build(b);
  const calc = (w, h) => w <= n && h <= m ? sa[w] * sb[h] : 0;

  let ans = 0;
  for (let i = 1; i * i <= k; i++) {
    if (k % i !== 0) {
      continue;
    }
    ans += calc(i, k / i);
    if (i !== k / i) {
      ans += calc(k / i, i);
    }
  }
  console.log(ans);
}

main();